/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/ec2/model/DescribeSpotFleetInstancesResponse.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>

#include <utility>

using namespace Aws::EC2::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;
using namespace Aws;

DescribeSpotFleetInstancesResponse::DescribeSpotFleetInstancesResponse()
{
}

DescribeSpotFleetInstancesResponse::DescribeSpotFleetInstancesResponse(const AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

DescribeSpotFleetInstancesResponse& DescribeSpotFleetInstancesResponse::operator =(const AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (rootNode.GetName() != "DescribeSpotFleetInstancesResponse")
  {
    resultNode = rootNode.FirstChild("DescribeSpotFleetInstancesResponse");
  }

  if(!resultNode.IsNull())
  {
    XmlNode spotFleetRequestIdNode = resultNode.FirstChild("spotFleetRequestId");
    if(!spotFleetRequestIdNode.IsNull())
    {
      m_spotFleetRequestId = StringUtils::Trim(spotFleetRequestIdNode.GetText().c_str());
    }
    XmlNode activeInstancesNode = resultNode.FirstChild("ActiveInstances");
    if(!activeInstancesNode.IsNull())
    {
      XmlNode activeInstancesMember = activeInstancesNode.FirstChild("item");
      while(!activeInstancesMember.IsNull())
      {
        m_activeInstances.push_back(activeInstancesMember);
        activeInstancesMember = activeInstancesMember.NextNode("item");
      }

    }
    XmlNode nextTokenNode = resultNode.FirstChild("nextToken");
    if(!nextTokenNode.IsNull())
    {
      m_nextToken = StringUtils::Trim(nextTokenNode.GetText().c_str());
    }
  }

  XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
  m_responseMetadata = responseMetadataNode;

  return *this;
}